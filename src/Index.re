// Entry point

[@bs.val] external document: Js.t({..}) = "document";

// We're using raw DOM manipulations here, to avoid making you read
// ReasonReact when you might precisely be trying to learn it for the first
// time through the examples later.
let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

module BuckleScript3987ReproOk = {
  let makeProps = (~value: string, ~onChange: (. string, int) => unit, ()) => {
    {"value": value, "onChange": onChange};
  };

  let make =
      (
        _props: {
          .
          "value": string,
          "onChange": (. string, int) => unit,
        },
      ) => {
    React.null;
  };
};

ReactDOMRe.render(
  <BuckleScript3987ReproOk value="test" onChange={(. _, _) => ()} />,
  makeContainer("ok"),
);

module BuckleScript3987ReproError = {
  [@react.component]
  let make = (~value: string, ~onChange: (. string, int) => unit) => {
    React.null;
  };
};

ReactDOMRe.render(
  <BuckleScript3987ReproError value="test" onChange={(. _, _) => ()} />,
  makeContainer("error"),
);
